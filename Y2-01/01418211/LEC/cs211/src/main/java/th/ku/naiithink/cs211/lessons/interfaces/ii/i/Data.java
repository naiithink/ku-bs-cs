package th.ku.naiithink.cs211.lessons.interfaces.ii.i;

import java.util.Arrays;

public class Data {

    public static double min(Object[] obj, MeasurableComparator measurableComparator) {
        Arrays.sort(obj, measurableComparator);
        return measurableComparator.getNaturalValueOf(obj);
    }
}
