package th.ku.naiithink.cs211.lessons.interfaces.ii.ii;

public class BankAccount
        implements Comparable<BankAccount> {

    private String owner;

    private double balance;

    public BankAccount(String owner, double balance) {
        this.owner = owner;
        this.balance = balance;
    }

    public String getOwner() {
        return owner;
    }

    public double getBalance() {
        return balance;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    @Override
    public String toString() {
        return "BankAccount [owner=" + owner + ", balance=" + balance + "]";
    }

    @Override
    public int compareTo(BankAccount other) {
        return this.balance - other.balance > 0 ? 1
                                                : this.balance == other.balance ? 0
                                                                                : -1;
    }
}
