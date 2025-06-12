
#include "library.h"


#include "CCL.h"
#include "osrng.h"
#include "cmac.h"
#include "hex.h"

using namespace CryptoPP;
using namespace std;


void cclOnDllLoad() {
    cclPrintf("SecOC DLL loaded successfully.");

    // 设置测量事件处理函数
    cclSetMeasurementPreStartHandler(&OnMeasurementPreStart);
    cclSetMeasurementStartHandler(&OnMeasurementStart);
    cclSetMeasurementStopHandler(&OnMeasurementStop);
}
void OnMeasurementPreStart() {
    uint8_t key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                  0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    uint8_t data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    uint8_t mac[16];
    CMAC<AES> cmac(key, sizeof(key));
    cmac.CalculateDigest(mac, data, sizeof(data));
    string macHex;
    HexEncoder encoder;
    encoder.Attach(new StringSink(macHex));
    encoder.Put(mac, sizeof(mac));
    encoder.MessageEnd();
    cclPrintf("CMAC: %s", macHex.c_str());
//    Canoe write窗口输出 CMAC: 4CDF0ABE65B1D047D632E7A0256BD3A4
}
void OnMeasurementStart(){
}
void OnMeasurementStop(){}