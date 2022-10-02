import softwareCon.lec.assg.interfaces.i.Data;
import softwareCon.lec.assg.interfaces.i.Car;
import softwareCon.lec.assg.interfaces.i.Product;

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
