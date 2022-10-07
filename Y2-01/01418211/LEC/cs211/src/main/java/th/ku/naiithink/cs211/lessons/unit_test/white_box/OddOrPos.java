package th.ku.naiithink.cs211.lessons.unit_test.white_box;

public class OddOrPos {

    public int oddOrPos(int[] x) {
        int count = 0;
        for (int i = 0; i < x.length; i++) {
            if (x[i] % 2 == 1 || x[i] > 0) {
                count++;
            }
        }
        return count;
    }
}
