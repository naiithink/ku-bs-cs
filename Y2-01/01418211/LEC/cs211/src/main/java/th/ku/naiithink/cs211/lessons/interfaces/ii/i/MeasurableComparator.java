package th.ku.naiithink.cs211.lessons.interfaces.ii.i;

import java.util.Comparator;

public interface MeasurableComparator<T>
        extends Comparator<T> {

    double getNaturalValueOf(T t);
}
