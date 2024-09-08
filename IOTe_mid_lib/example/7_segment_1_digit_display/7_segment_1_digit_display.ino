#include <IoTe.h>

// เอาไว้เเสดงผลบน 7-segment credit-temz

void setup() {
  /* เริ่มต้นการประกาศ pin สำหรับ 7 sigment
     Segment_begin(A,B,C,D,E,F,G,DP,
     ACTIVE_PIN_1,
     ACTIVE_PIN_2,
     ACTIVE_PIN_3,
     ACTIVE_PIN_4
     ) 
  */
  Segment_begin(11,A1,A2,2,4,7,8,13,5,6,9,10);

}

void loop() {
    /* เเสดงผล 7 segment 
       displaysegment( 
        เลขที่จะเเสดงผล,
        จุดทศนิยม,
        เเสดงผล digit
       )
    */
    for(int i = 0;i < 9;i++){
      delay(150);y
      displaysegment(i,0,1);
    } 
}
