package th.ku.naiithink.cs211.lessons.interfaces.i.i;

public class Data {

    public static double min(Measurable<Double>[] measurables) {
        Measurable<Double> result = measurables[0];

        for (int i = 1, lim = measurables.length; i < lim; ++i) {
            if (result.measure() > measurables[i].measure()) {
                result = measurables[i];
            }
        }

        return result.measure();
    }
}
