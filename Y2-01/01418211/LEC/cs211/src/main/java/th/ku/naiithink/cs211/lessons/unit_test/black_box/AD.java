package th.ku.naiithink.cs211.lessons.unit_test.black_box;

public class AD {
    protected AD() {}

    public static boolean isLeapYear(int yearInAD) {
        if (yearInAD <= 0) {
            throw new IllegalArgumentException(Integer.toString(yearInAD));
        }

        if (yearInAD % 400 == 0)
            return true;
        else if (yearInAD % 100 != 0
                 && yearInAD % 4 == 0)
            return true;

        return false;
    }
}
