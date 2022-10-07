package th.ku.naiithink.cs211.lessons.interfaces.i.ii;

import java.util.Arrays;

public final class Main {

    public static void main(String[] args) {
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

        Sorter.sort(strings);

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
            Pet
            ---""");
        System.out.println();

        Pet[] pets = {
            new Pet("Tom", "Felis", 6),
            new Pet("Spike", "Canine", 12),
            new Pet("Jerry", "Rattus", 4),
        };

        System.out.println("Before sort");
        for (Pet pet : pets) {
            System.out.println(pet);
        }

        Arrays.sort(pets);

        System.out.println();
        System.out.println("After sort");
        for (Pet pet : pets) {
            System.out.println(pet);
        }
    }
}
