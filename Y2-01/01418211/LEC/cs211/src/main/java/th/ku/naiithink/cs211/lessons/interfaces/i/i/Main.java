package th.ku.naiithink.cs211.lessons.interfaces.i.i;

public final class Main {

    public static void main(String[] args) {
        Car[] cars = {
            new Car("A", 299),
            new Car("B", 9),
            new Car("C", 140)
        };

        System.out.println(Data.min(cars));
    }
}
