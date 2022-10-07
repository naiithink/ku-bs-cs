package th.ku.naiithink.cs211.lessons.interfaces.ii.ii;

import java.util.Comparator;

public class Sorter {

    public static void sort(Object[] objects, Comparator comparator) {
        for (int i = 0; i < objects.length - 1; i++) {// i แบ่งส่วนเรียงแล้วกับยังไม่เรียง
            int minPos = i;
            for (int j = i + 1; j < objects.length; j++) { // วนลูปหาค่าน้อยสุด
                if (comparator.compare(objects[j], objects[minPos]) < 0) {
                    minPos = j;
                }
            }

            // สลับข้อมูลใน minPos และ i ทําให้ข้อมูลใน minPos ไปอยู่ส่วนที่เรียงแล้ว
            Object temp = objects[minPos];
            objects[minPos] = objects[i];
            objects[i] = temp;
        }
    }
}
