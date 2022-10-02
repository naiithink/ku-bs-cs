package softwareCon.lec.assg.interfaces.i;

public class Car
        implements Comparable<Car>,
                   Measurable {

    private String license;

    private double kiloDriven; // ระยะทางการขับ

    public Car(String license, double kiloDriven) {
        this.license = license;
        this.kiloDriven = kiloDriven;
    }

    public String getLicense() {
        return license;
    }

    public double getKiloDriven() {
        return kiloDriven;
    }

    @Override
    public String toString() {
        return "Car [kiloDriven=" + kiloDriven + ", license=" + license + "]";
    }

    @Override
    public int compareTo(Car other) {
        return this.kiloDriven - other.kiloDriven;
    }

    @Override
    public <T> T measure() {
        return kiloDriven;
    }
}
