package softwareCon.lec.assg.interfaces.i;

@FunctionalInterface
public interface Measurable
        extends Comparable {

    <T> T measure();
}
