package softwareCon.lec.assg.interfaces.i;

import java.util.Objects;

public class Data {

    public static double min(Comparable[] comparables) {
        Comparable result = comparables[0];

        for (int i = 1, lim = comparables.length; i < lim; ++i) {
            if (result.compareTo(comparables[i]) < 0) {
                result = comparables[i];
            }
        }

        // Double doubleResult = result.measure();

        return result.measure(); // doubleResult.doubleValue();
    }
}
