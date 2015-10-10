#include<iostream>

// #include"audio_device_impl.h"
#include"audio_device.h"
#include "base/scoped_ref_ptr.h"
#include "audio_processing/aec/include/echo_cancellation.h"

#include<fstream>
using namespace webrtc;
using namespace std;

class MyAudioTransport : public AudioTransport{
public:
  MyAudioTransport(){};
  virtual ~MyAudioTransport(){};
  virtual int32_t RecordedDataIsAvailable(const void* audioSamples,
                                          const size_t nSamples,
                                          const size_t nBytesPerSample,
                                          const uint8_t nChannels,
                                          const uint32_t samplesPerSec,
                                          const uint32_t totalDelayMS,
                                          const int32_t clockDrift,
                                          const uint32_t currentMicLevel,
                                          const bool keyPressed,
                                          uint32_t& newMicLevel) {
    cout<<"recorded data is available"<<endl;
    return 0;
  }

  virtual int32_t NeedMorePlayData(const size_t nSamples,
                                   const size_t nBytesPerSample,
                                   const uint8_t nChannels,
                                   const uint32_t samplesPerSec,
                                   void* audioSamples,
                                   size_t& nSamplesOut,
                                   int64_t* elapsed_time_ms,
                                   int64_t* ntp_time_ms){
    cout<<"need more play data"<<endl;
    return 0;
  }

  // Method to pass captured data directly and unmixed to network channels.
  // |channel_ids| contains a list of VoE channels which are the
  // sinks to the capture data. |audio_delay_milliseconds| is the sum of
  // recording delay and playout delay of the hardware. |current_volume| is
  // in the range of [0, 255], representing the current microphone analog
  // volume. |key_pressed| is used by the typing detection.
  // |need_audio_processing| specify if the data needs to be processed by APM.
  // Currently WebRtc supports only one APM, and Chrome will make sure only
  // one stream goes through APM. When |need_audio_processing| is false, the
  // values of |audio_delay_milliseconds|, |current_volume| and |key_pressed|
  // will be ignored.
  // The return value is the new microphone volume, in the range of |0, 255].
  // When the volume does not need to be updated, it returns 0.
  // TODO(xians): Remove this interface after Chrome and Libjingle switches
  // to OnData().
  virtual int OnDataAvailable(const int voe_channels[],
                              int number_of_voe_channels,
                              const int16_t* audio_data,
                              int sample_rate,
                              int number_of_channels,
                              size_t number_of_frames,
                              int audio_delay_milliseconds,
                              int current_volume,
                              bool key_pressed,
                              bool need_audio_processing) {
    cout<<"on data available"<<endl;
    return 0;
  }

  // Method to pass the captured audio data to the specific VoE channel.
  // |voe_channel| is the id of the VoE channel which is the sink to the
  // capture data.
  // TODO(xians): Remove this interface after Libjingle switches to
  // PushCaptureData().
  virtual void OnData(int voe_channel,
                      const void* audio_data,
                      int bits_per_sample,
                      int sample_rate,
                      int number_of_channels,
                      size_t number_of_frames){
    cout<<"on data"<<endl;
  }

  // Method to push the captured audio data to the specific VoE channel.
  // The data will not undergo audio processing.
  // |voe_channel| is the id of the VoE channel which is the sink to the
  // capture data.
  // TODO(xians): Make the interface pure virtual after Libjingle
  // has its implementation.
  virtual void PushCaptureData(int voe_channel,
                               const void* audio_data,
                               int bits_per_sample,
                               int sample_rate,
                               int number_of_channels,
                               size_t number_of_frames) {
    cout<<"push capture data"<<endl;
  }

  // Method to pull mixed render audio data from all active VoE channels.
  // The data will not be passed as reference for audio processing internally.
  // TODO(xians): Support getting the unmixed render data from specific VoE
  // channel.
  virtual void PullRenderData(int bits_per_sample,
                              int sample_rate,
                              int number_of_channels,
                              size_t number_of_frames,
                              void* audio_data,
                              int64_t* elapsed_time_ms,
                              int64_t* ntp_time_ms) {
    cout<<"pull render data"<<endl;
  }
};
int main(){

  ///// aec test
   char * buffer1;
   char * buffer2;

   long size;
   char fromPeer[]="/Users/lihaifeng/work/FromPeer.pcm";

   ifstream in (fromPeer, ios::in|ios::binary|ios::ate);  
   size = in.tellg();
   cout<<"far end size:"<<size<<endl;
   in.seekg (0, ios::beg);  
   buffer1 = new char [size];
    
   in.read (buffer1, size);  
   in.close();
        
   char toPeer[]="/Users/lihaifeng/work/ToPeer.pcm";
   ifstream in2 (toPeer, ios::in|ios::binary|ios::ate);  
   // size = in2.tellg();
   // cout<<"near end size:"<<size<<endl;        
   in.seekg (0, ios::beg);  
   buffer2 = new char [size];  
   in2.read (buffer2, size);  
   in2.close();

  
    float*farend,*nearend;
    short *output;
   int sample_size=size/2;
   farend=new float[sample_size];
   nearend=new float[sample_size];
    output=new short[sample_size];
   short* ptr_near = (short*)buffer2;
   short* ptr_far = (short*)buffer1;
   for(int i = 0; i<sample_size;i++){
     nearend[i] = (float)ptr_near[i];
     farend[i] = (float)ptr_far[i];
   }
   delete [] buffer1;
   delete [] buffer2;
    
    	void *aecmInst;
	aecmInst = WebRtcAec_Create();
    int sample = 16000;
	WebRtcAec_Init(aecmInst, sample, sample);

    int count = 0;
    float*ptr_farend=farend;
    float*ptr_nearend=nearend;
    short*ptr_output=output;
    int block_size=160;
    float *temp=new float[160];
    while (count<sample_size) {
        WebRtcAec_BufferFarend(aecmInst,ptr_farend,sample_size);
        WebRtcAec_Process(aecmInst, &ptr_nearend, 1, &temp, block_size, 100, 0);
        for (int i =0; i<block_size; i++) {
            ptr_output[i]=static_cast<short>(temp[i]);
        }
        count+=block_size;
        ptr_farend+=block_size;
        ptr_nearend+=block_size;
        ptr_output+=block_size;
    }
//	while(NN == fread(far_frame, sizeof(WebRtc_Word16), NN, fp_far))
//	{
//		fread(near_frame, sizeof(WebRtc_Word16), NN, fp_near);
//		WebRtcAec_BufferFarend(aecmInst, far_frame, NN);
//		WebRtcAec_Process(aecmInst, near_frame, 0, out_frame, 0, NN,NN,100);
//		fwrite(out_frame, sizeof(WebRtc_Word16), NN, fp_out);
//	}

	WebRtcAec_Free(aecmInst);
   char outputPath[]="/Users/lihaifeng/work/output.pcm";
   ofstream outfile (outputPath, ios::out|ios::binary);
    outfile.write((char*)temp, sample_size*2);
  ///// aec test end

  

  
//  ///////audio device test
//  rtc::scoped_refptr<AudioDeviceModule> audio_device(CreateAudioDeviceModule(0,AudioDeviceModule::kPlatformDefaultAudio));
//  if(audio_device.get()==nullptr){
//    std::cout<<"failed"<<std::endl;
//    return 1;
//  }
//  auto cond = audio_device->Init();
//  auto devices_play = audio_device->PlayoutDevices();
//  cout<<"available playout device:"<<devices_play<<endl;
//  auto devices_record = audio_device->RecordingDevices();
//  cout<<"available record device:"<<devices_record<<endl;
//  MyAudioTransport myAudioTransport;
//  audio_device->RegisterAudioCallback(&myAudioTransport);
//    
//  char name[kAdmMaxDeviceNameSize];
//  char guid[kAdmMaxGuidSize];
//  for(int i = 1;i<devices_play+1;i++){
//    cond = audio_device->PlayoutDeviceName(i,name,guid);
//    cout<<"play device number:"<<i<<" name:"<<name<<" guid:"<<guid<<endl;
//  }
//  for(int i = 1;i<devices_record+1;i++){
//    cond = audio_device->RecordingDeviceName(i,name,guid);
//    cout<<"record device number:"<<i<<" name:"<<name<<" guid:"<<guid<<endl;
//  }
//  bool available;
//  // cond = audio_device->SetPlayoutDevice(1);
//  // cout<<"set play out device:"<<cond<<endl;
//
//  audio_device->SetRecordingDevice(1);
//  cout<<"set record device:"<<cond<<endl;
//  cond = audio_device->RecordingIsAvailable(&available);
//  cout<<"device available:"<<cond<<endl;
//  if(available){
//    cond = audio_device->InitRecording();
//    cout<<"init record device:"<<cond<<endl;
//
//    cond = audio_device->SetAGC(false);
//    cout<<"set agc :"<<cond<<endl;
//    cond = audio_device->StartRecording();
//    cout<<"start recording :"<<cond<<endl;
//    cond = audio_device->StopRecording();
//    cout<<"stop recording :"<<cond<<endl;
//  }
//
//  // if(audio_device->PlayoutIsAvailable()){
//  //   cond = audio_device->InitPlayout();
//  //   cout<<"init playout device:"<<cond<<endl;
//  // }    
//
//  ///////audio device test end
  return 0;
}
