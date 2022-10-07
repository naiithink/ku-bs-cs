package th.ku.naiithink.cs211.lessons.interfaces.ii.ii;

import java.util.Arrays;
import java.util.Comparator;

public final class Main {

    public static void main(String[] args) {
        Comparator<String> stringComparator = (s1, s2) -> {
            return s1.compareTo(s2);
        };

        System.out.println();
        System.out.println("""
                String
                ------""");
        System.out.println();

        String[] strings = {
                "x",
                "z",
                "y"
        };

        System.out.println("Before sort");
        for (String string : strings) {
            System.out.println(string);
        }

        Sorter.sort(strings, stringComparator);

        System.out.println();
        System.out.println("After sort");
        for (String string : strings) {
            System.out.println(string);
        }

        System.out.println();
        System.out.println("""
                BankAccount
                -----------""");
        System.out.println();

        BankAccount[] accounts = {
                new BankAccount("Hermione", 10),
                new BankAccount("Harry", 0),
                new BankAccount("Ron", 100)
        };

        System.out.println("Before sort");
        for (BankAccount account : accounts) {
            System.out.println(account);
        }

        Arrays.sort(accounts);

        System.out.println();
        System.out.println("After sort");
        for (BankAccount account : accounts) {
            System.out.println(account);
        }

        System.out.println();
        System.out.println("""
                Animal
                ---""");
        System.out.println();

        Animal[] pets = {
                new Animal("Tom", "Felis", 6),
                new Animal("Spike", "Canine", 12),
                new Animal("Jerry", "Rattus", 4),
        };

        System.out.println("Before sort");
        for (Animal pet : pets) {
            System.out.println(pet);
        }

        Arrays.sort(pets);

        System.out.println();
        System.out.println("After sort");
        for (Animal pet : pets) {
            System.out.println(pet);
        }
    }
}
