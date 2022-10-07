package th.ku.naiithink.cs211.lessons.interfaces.i.ii;

public class Sorter {

    public static void sort(Comparable[] comparables) {
        for (int i = 0; i < comparables.length - 1; i++) {// i แบ่งส่วนเรียงแล้ว กับยังไม่เรียง
            int minPos = i;
            for (int j = i + 1; j < comparables.length; j++) { // วนลูปหาค่าน้อยสุด ]
                if (comparables[j].compareTo(comparables[minPos]) < 0) {
                    minPos = j;
                }
            }

            // สลับข้อมูลใน minPos และ i ทําให้ข้อมูลใน minPos ไปอยสู่ส่วนที่เรียงแล้ว
            Object temp = comparables[minPos];
            comparables[minPos] = comparables[i];
            comparables[i] = (Comparable) temp;
        }
    }
}
