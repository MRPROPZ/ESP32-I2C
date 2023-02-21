void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);     // อัตราการเปลี่ยนข้อมูล bps
    ledcSetup(0, 5000, 8);  // กำหนดค่าการทำงานของวงจรไทเมอร์ ช่องสัญญาณ, ความถี่, ความละเอียด
    ledcSetup(1, 5000, 8);  // กำหนดค่าการทำงานของวงจรไทเมอร์ ช่องสัญญาณ, ความถี่, ความละเอียด
    ledcSetup(2, 5000, 8);  // กำหนดค่าการทำงานของวงจรไทเมอร์ ช่องสัญญาณ, ความถี่, ความละเอียด
    ledcAttachPin(23, 0);   // แดง อยู่ช่อง 0
    ledcAttachPin(19, 1);   // เขียว อยู่ช่อง 1
    ledcAttachPin(18, 2);   // ฟ้า อยู่ช่อง 2
    pinMode(33, OUTPUT);    // relay
    pinMode(32, OUTPUT);    // buzzer
    digitalWrite(32, HIGH); // ปิด buzzer
}

void loop() {
    // put your main code here, to run repeatedly:
    while (Serial.available() == 0) {}  // รอข้อมูลที่มีอยู่
    String str = Serial.readString();   // อ่านข้อมูลออกมาเป็นข้อความ
    Serial.print("I received: ");       // แสดงข้อความ
    Serial.println(str);                // แสดงข้อความ ขึ้นบรรทัดใหม่
    str.trim();                         // ลบ \r \n ช่องว่างใดๆ ที่ส่วนท้ายของสตริง
    if (str == "lime") {
        ledcWrite(0, 164);  // แดง
        ledcWrite(1, 196);  // เขียว
        ledcWrite(2, 0);    // น้ำเงิน
    }
    if (str == "green") {
        ledcWrite(0, 0);    // แดง
        ledcWrite(1, 255);  // เขียว
        ledcWrite(2, 23);   // น้ำเงิน
    }
    if (str == "emerald") {
        ledcWrite(0, 0);    // แดง
        ledcWrite(1, 138);  // เขียว
        ledcWrite(2, 0);    // น้ำเงิน
    }
    if (str == "teal") {
        ledcWrite(0, 0);    // แดง
        ledcWrite(1, 171);  // เขียว
        ledcWrite(2, 169);  // น้ำเงิน
    }
    if (str == "cyan") {
        ledcWrite(0, 27);   // แดง
        ledcWrite(1, 161);  // เขียว
        ledcWrite(2, 226);  // น้ำเงิน
    }
    if (str == "cobalt") {
        ledcWrite(0, 0);   // แดง
        ledcWrite(1, 80);  // เขียว
        ledcWrite(2, 239); // น้ำเงิน
    }
    if (str == "indigo") {
        ledcWrite(0, 106);  // แดง
        ledcWrite(1, 0);    // เขียว
        ledcWrite(2, 255);  // น้ำเงิน
    }
    if (str == "violet") {
        ledcWrite(0, 170);  // แดง
        ledcWrite(1, 0);    // เขียว
        ledcWrite(2, 255);  // น้ำเงิน
    }
    if (str == "pink") {
        ledcWrite(0, 244);  // แดง
        ledcWrite(1, 114);  // เขียว
        ledcWrite(2, 208);  // น้ำเงิน
    }
    if (str == "magenta") {
        ledcWrite(0, 216);  // แดง
        ledcWrite(1, 0);    // เขียว
        ledcWrite(2, 115);  // น้ำเงิน
    }
    if (str == "crimson") {
        ledcWrite(0, 162);  // แดง
        ledcWrite(1, 0);    // เขียว
        ledcWrite(2, 37);  // น้ำเงิน
    }
    if (str == "red") {
        ledcWrite(0, 255); // แดง
        ledcWrite(1, 0);   // เขียว
        ledcWrite(2, 0);   // น้ำเงิน
    }
    if (str == "orange") {
        ledcWrite(0, 250);  // แดง
        ledcWrite(1, 104);  // เขียว
        ledcWrite(2, 0);    // น้ำเงิน
    }
    if (str == "amber") {
        ledcWrite(0, 240);  // แดง
        ledcWrite(1, 163);  // เขียว
        ledcWrite(2, 10);   // น้ำเงิน
    }
    if (str == "yellow") {
        ledcWrite(0, 227);  // แดง
        ledcWrite(1, 200);  // เขียว
        ledcWrite(2, 0);    // น้ำเงิน
    }
    if (str == "brown") {
        ledcWrite(0, 130);  // แดง
        ledcWrite(1, 90);   // เขียว
        ledcWrite(2, 44);   // น้ำเงิน
    }
    if (str == "olive") {
        ledcWrite(0, 109);   // แดง
        ledcWrite(1, 135);   // เขียว
        ledcWrite(2, 100);   // น้ำเงิน
    }
    if (str == "steel") {
        ledcWrite(0, 100);   // แดง
        ledcWrite(1, 118);   // เขียว
        ledcWrite(2, 135);   // น้ำเงิน
    }
    if (str == "mauve") {
        ledcWrite(0, 118);   // แดง
        ledcWrite(1, 96);    // เขียว
        ledcWrite(2, 138);   // น้ำเงิน
    }
    if (str == "taupe") {
        ledcWrite(0, 135);   // แดง
        ledcWrite(1, 121);   // เขียว
        ledcWrite(2, 78);    // น้ำเงิน
    }
    if (str == "ron") {     // เปิด relay
       digitalWrite(33, HIGH);
    }
    if (str == "roff") {     // ปิด relay
       digitalWrite(33, LOW);
    }
    if (str == "bon") {     // เปิด buzzer
       digitalWrite(32, LOW);
    }
    if (str == "boff") {     // ปิด buzzer
       digitalWrite(32, HIGH);
    }
    if (str == "dance") {     // เปลี่ยนสีไฟ
       for (int i = 0; i < 5; i++) {
            ledcWrite(1, 255);  // เขียวเปิด
            delay(1000);
            ledcWrite(1, 0);    // เขียวปิด
            ledcWrite(0, 255);  // แดงเปิด
            delay(1000);
            ledcWrite(0, 0);    // แดงปิด
            ledcWrite(2, 255);  // ฟ้าเปิด
            delay(1000);
            ledcWrite(2, 0);    // ฟ้าปิด
       }
    }
}