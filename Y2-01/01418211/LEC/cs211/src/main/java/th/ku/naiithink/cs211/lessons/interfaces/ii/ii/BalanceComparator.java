package th.ku.naiithink.cs211.lessons.interfaces.ii.ii;

import java.util.Comparator;

public class BalanceComparator
        implements Comparator<BankAccount> {

    @Override
    public int compare(BankAccount ac1, BankAccount ac2) {
        return ac1.getBalance() > ac2.getBalance() ? 1
                                                   : ac1.getBalance() == ac2.getBalance() ? 0
                                                                                          : -1;
    }
}
