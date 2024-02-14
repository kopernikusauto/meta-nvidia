PV="12.0.1"
PR="r0"

SRC_URI="https://developer.download.nvidia.com/compute/cuda/$PV/local_installers/cuda_$PV_525.85.12_linux.run"

wget -P /opt/ $SRC_URI
chmod +x /opt/cuda_12.0.1_525.85.12_linux.run

echo "extracting cuda"
cd /opt
./cuda_12.0.1_525.85.12_linux.run --silent --toolkit --samples --installpath=/opt/cuda-install
