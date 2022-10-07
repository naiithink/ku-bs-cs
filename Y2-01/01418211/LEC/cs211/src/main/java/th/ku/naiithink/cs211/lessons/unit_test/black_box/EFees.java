package th.ku.naiithink.cs211.lessons.unit_test.black_box;

public class EFees {

    private double minimumFee;

    private static double interestA = 3.25;

    private static double interestB = 4.22;

    private static double interestC = 4.42;

    public EFees(double minimumFee) {
        this.minimumFee = minimumFee;
    }

    public double computeFeeOf(int units) {
        double total;
        double interest;

        if (units <= 150) {
            interest = interestA;
        } else if (units > 400) {
            interest = interestC;
        } else {
            interest = interestB;
        }

        total = minimumFee + units * interest;

        return total;
    }
}
