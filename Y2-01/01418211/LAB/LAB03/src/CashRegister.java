public class CashRegister {
    private int itemCount;
    private double subTotal;
    private MemberCard memberCard;
    private double total;
    private double receivedCash;
    private double change;

    public CashRegister() {
        this.itemCount = 0;
        this.subTotal = 0.0;
        this.total = 0;
        this.receivedCash = 0;
        this.change = 0;
    }

    public int getItemCount() {
        return itemCount;
    }

    public void setItemCount(int itemCount) {
        this.itemCount = itemCount;
    }

    public double getSubTotal() {
        return subTotal;
    }

    public void setSubTotal(double subTotal) {
        this.subTotal = subTotal;
    }

    public MemberCard getMemberCard() {
        return memberCard;
    }

    public void setMemberCard(MemberCard memberCard) {
        this.memberCard = memberCard;
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    public double getReceivedCash() {
        return receivedCash;
    }

    public void setReceivedCash(double receivedCash) {
        this.receivedCash = receivedCash;
    }

    public double getChange() {
        return change;
    }

    public void setChange(double change) {
        this.change = change;
    }

    public void setMemberCard(String name,
                              String phoneNumber,
                              double purchaseStat,
                              int eStampCount) {
        this.memberCard = new MemberCard(name, phoneNumber, purchaseStat, eStampCount);
    }

    public void purchaseItem(double purchase) {
        if (purchase < 0) {
            System.err.println("Warning: argument 'purchase' less than '0.0'.");
            // System.exit(1);
            return;
        }

        this.subTotal += purchase;
        this.itemCount++;
    }

    public void pay (double cash, int stamp) {
        double subTotal = this.subTotal;
        double total = 0.0;
        double discount = 0.0;
        int eStampCount;

        if (cash < 0.0 || stamp < 0) {
            System.err.println("Invalid argument.");
            return;
        }

        if (this.memberCard != null
            && (eStampCount = this.memberCard.getEStampCount()) >= stamp)
            discount = (double) eStampCount * 2.0;
        else
            discount = (double) stamp;

        if (discount > subTotal)
            discount = subTotal;

        total = subTotal - discount;

        if (cash < total) {
            System.err.println("Not enough cash.");
            return;
        }

        change = cash - total;

        this.subTotal = subTotal;
        this.total = total;
        this.receivedCash = cash;
        this.change = change;

        if (this.memberCard != null)
            this.memberCard.useStamp(stamp);
    }

    public void clear() {
        this.itemCount = 0;
        this.subTotal = 0.0;
        this.memberCard = null;
        this.total = 0.0;
        this.receivedCash = 0.0;
        this.change = 0.0;
    }

    @Override
    public String toString() {
        return "CashRegister{" +
                "itemCount=" + itemCount +
                ", subTotal=" + subTotal +
                ", memberCard=" + memberCard +
                ", total=" + total +
                ", receivedCash=" + receivedCash +
                ", change=" + change +
                '}';
    }
}
