# thunderbird-onvif
Implementation of ONVIF Profile S, providing device management for networked camera streams over SOAP protocol.

# Usage
## Running
Type the following command:
```console
./onvif-server -c config.yaml
```
## Configuration file
```yaml
server:
  username:  luminosity                           # username for authentication in ONVIF
  password:  123456                               # password for authentication in ONVIF
  http_port: 8080                                 # http port for ONVIF
  address:   nuc5.local                           # address of NUC
  devices:
  - token:     camera0                            # internal ONVIF identifier
    name:      Zach's Really Cool Camera          # friendly name of device
    width:     1920                               # width of RTSP stream
    height:    1080                               # height of RTSP stream
    pixformat: V4L2_PIX_FMT_H264                  # pixel format of RTSP stream
    rtsp_port: 7001                               # rtsp stream port
    rtsp_uri:  rtsp://nuc5.local:7001/stream      # uri of rtsp stream
    ptz_uri:   http://nuc5.local:6969/cam/pi5/0/  # uri for PTZ control of camera

  - token:     camera1
    name:      Zach's Other Cool Camera
    width:     1920
    height:    1080
    pixformat: V4L2_PIX_FMT_H264
    rtsp_port: 7002
    rtsp_uri:  rtsp://nuc5.local:7002/stream
    ptz_uri:   http://nuc5.local:6969/cam/pi5/2/
```

# Source Code Configs
## Building
1) Clone the repository:  
```
git clone https://github.com/ASU-LL/thunderbird-onvif
```
2) Install necessary libraries for gSOAP protocol and YAML parser:
```
sudo apt-get install -y --no-install-recommends gsoap libgsoap-dev libssl-dev zlib1g-dev libyaml-cpp-dev libcurl4-openssl-dev
```
3) Run make (this will take ~2 minutes):
```
cd thunderbird-onvif
make
```