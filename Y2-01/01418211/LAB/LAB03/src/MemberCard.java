import java.lang.reflect.Member;

public class MemberCard {
    private String name;
    private String phoneNumber;
    private double purchaseStat;
    private int eStampCount;

    public MemberCard(String name,
                      String phoneNumber,
                      double purchaseStat,
                      int eStampCount) {
        if (name == null) {
            System.err.println("Warning: argument 'name' is 'null'.");
            // System.exit(1);
        }

        if (phoneNumber == null) {
            System.err.println("Warning: argument 'phoneNumber' is 'null'.");
            // System.exit(1);
        }

        if (purchaseStat < 0) {
            System.err.println("Warning: argument 'purchaseStat' less than '0.0'.");
            // System.exit(1);
        }

        if (eStampCount < 0) {
            System.err.println("Warning: argument 'eStampCount' less than '0'.");
            // System.exit(1);
        }

        this.name = name;
        this.phoneNumber = phoneNumber;
        this.purchaseStat = purchaseStat;
        this.eStampCount = eStampCount;
    }

    public MemberCard(String name, String phoneNumber) {
        this(name, phoneNumber, 0.0, 0);

        if (name == null) {
            System.err.println("Warning: argument 'name' is 'null'.");
            // System.exit(1);
        }

        if (phoneNumber == null) {
            System.err.println("Warning: argument 'phoneNumber' is 'null'.");
            // System.exit(1);
        }
    }

    public MemberCard(String name, String phoneNumber, int eStampCount) {
        this(name, phoneNumber, 0.0, eStampCount);

        if (name == null) {
            System.err.println("Warning: argument 'name' is 'null'.");
            // System.exit(1);
        }

        if (phoneNumber == null) {
            System.err.println("Warning: argument 'phoneNumber' is 'null'.");
            // System.exit(1);
        }

        if (eStampCount < 0) {
            System.err.println("Warning: argument 'eStampCount' less than '0'.");
            // System.exit(1);
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public double getPurchaseStat() {
        return purchaseStat;
    }

    public void setPurchaseStat(double purchaseStat) {
        this.purchaseStat = purchaseStat;
    }

    public int getEStampCount() {
        return eStampCount;
    }

    public void setEStampCount(int eStampCount) {
        this.eStampCount = eStampCount;
    }

    public void addPurchase(double purchase) {
        if (purchase < 0)
            return;

        int gotStamps = (int) purchase / 50;

        this.eStampCount += gotStamps;
        this.purchaseStat += purchase;
    }

    public boolean useStamp(int stamp) {
        boolean result;

        if (stamp <= this.eStampCount) {
            this.eStampCount -= stamp;
            result = true;
        } else {
            result = false;
        }

        return result;
    }

    @Override
    public String toString() {
        return "MemberCard{" +
                "name='" + name + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", purchaseStat=" + purchaseStat +
                ", eStampCount=" + eStampCount +
                '}';
    }
}
