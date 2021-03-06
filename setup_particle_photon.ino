// Code for the laser servo controller

// PIN configuration
// PIN# PIN_name        Connection          Type
// 5    WKUP            DS3                 Digital In
// 6    DAC             DS2                 Digital In
// 7    A5              S3_output_enable    Digital Out
// 8    A4              S2_curr_int         Digital Out
// 9    A3              S1_input            Digital Out
// 10   A2              S4_piezo_enable     Digital Out
// 11   A1              pz_out_buffer       Analog In
// 12   A0              transmission        Analog In
// 13   D0              S5_piezo_int        Digital Out
// 14   D1              S6_piezo_offset     Ditigal Out
// -----------------------------------------------------
// 15   D2              MOSI_SPI            Digital Out
// 17   D4              SCK_SPI             Digital Out
// 18   D5              SS_SPI              Digital Out
// 19   D6              LDAC_               Digital Out
// 20   D7              DS1                 Digital In

int DS3 = WKP;
int DS2 = DAC;
int S3_output_enable = A5;
int S2_curr_int = A4;
int S1_input = A3;
int S4_piezo_enable = A2;
int pz_out_buffer = A1;
int transmission = A0;
int S5_piezo_int = D0;
int S6_piezo_offset = D1;
int DS1 = D7;
int LDAC_ = D6;

uint8_t test_upper = 0x80;
uint8_t test_lower = 0x00;

void setup() {
    pinMode(DS1, INPUT);
    pinMode(DS2, INPUT);
    pinMode(DS3, INPUT);

    pinMode(S1_input, OUTPUT);
    pinMode(S2_curr_int, OUTPUT);
    pinMode(S3_output_enable, OUTPUT);


    pinMode(S4_piezo_enable, OUTPUT);
    pinMode(S5_piezo_int, OUTPUT);
    pinMode(S6_piezo_offset, OUTPUT);

    pinMode(LDAC_, OUTPUT);

    SPI1.setBitOrder(MSBFIRST);
    SPI1.setClockSpeed(15, MHZ);
    SPI1.begin();
    digitalWrite(LDAC_, LOW);
    digitalWrite(D5, HIGH);
    
    digitalWrite(D5, LOW);
    SPI1.transfer(test_upper);
    SPI1.transfer(test_lower);
    digitalWrite(D5, HIGH);

}

void loop() {

}
