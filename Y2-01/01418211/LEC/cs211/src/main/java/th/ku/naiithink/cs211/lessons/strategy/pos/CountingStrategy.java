package th.ku.naiithink.cs211.lessons.strategy.pos;

import java.util.List;

@FunctionalInterface
public interface CountingStrategy<T> {

    int count(final List<T> data);
}
