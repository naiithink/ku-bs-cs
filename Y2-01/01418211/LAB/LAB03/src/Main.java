public class Main {
    public static void main(String[] args) {
        System.out.println("""
            
            The MemberCard class
            ========================
            """);

        // Smith's Card
        MemberCard smithCard = new MemberCard("Smith", "a");

        // Smith Day 1
        smithCard.addPurchase(450);

        // Smith Day 2
        smithCard.addPurchase(988.5);

        // Smith Day 3
        smithCard.addPurchase(2_298.7);

        // Current Smith's Card State
        System.out.printf("""
            %s's
            ------------------------
            Total purchased: %.2f
            Current E-Stamp: %d
            """, smithCard.getName(), smithCard.getPurchaseStat(), smithCard.getEStampCount());

        System.out.println();

        // Wright's Card
        MemberCard wrightCard = new MemberCard("Wright", "06123456789");

        // Wright Day 1
        wrightCard.addPurchase(135);

        // Wright Day 2
        wrightCard.addPurchase(345);

        // Wright Day 3
        wrightCard.addPurchase(723);

        // Current Wright's Card State
        System.out.printf("""
            %s's
            ------------------------
            Total purchased: %.2f
            Current E-Stamp: %d
            """, wrightCard.getName(), wrightCard.getPurchaseStat(), wrightCard.getEStampCount());

        System.out.println("""
            
            The CashRegister class
            ========================
            """);

        CashRegister register = new CashRegister();

        // Smith's
        System.out.println("""
            Smith's
            ------------------------""");

        register.purchaseItem(15);
        register.purchaseItem(16.5);
        register.purchaseItem(200);
        register.purchaseItem(24);
        register.purchaseItem(18);
        register.purchaseItem(129.9);
        register.purchaseItem(30);

        register.setMemberCard("Smith", "a", 0.0, 12);

        System.out.printf("""
                Item count: %d
                Subtotal:   %.2f
                """, register.getItemCount(), register.getSubTotal());

        System.out.println();

        register.pay(500, 12);

        System.out.printf("""
                Subtotal:   %.2f
                Total:      %.2f
                Change:     %.2f
                """, register.getSubTotal(), register.getTotal(), register.getChange());

        register.clear();

        System.out.println();

        // Razr's
        System.out.println("""
            Razr's
            ------------------------""");

        register.purchaseItem(47);
        register.purchaseItem(99);
        register.purchaseItem(65);
        register.purchaseItem(20.5);
        register.purchaseItem(29);

        System.out.printf("""
                Item count: %d
                Subtotal:   %.2f
                """, register.getItemCount(), register.getSubTotal());

        System.out.println();

        register.pay(300, 30);

        System.out.printf("""
                Subtotal:   %.2f
                Total:      %.2f
                Change:     %.2f
                """, register.getSubTotal(), register.getTotal(), register.getChange());

        register.clear();

        System.out.println();

        // naiithink's
        System.out.println("""
            naiithink's
            ------------------------""");

        register.purchaseItem(4);
        register.purchaseItem(8);
        register.purchaseItem(16);
        register.purchaseItem(32);
        register.purchaseItem(64);
        register.purchaseItem(128);
        register.purchaseItem(256);
        register.purchaseItem(512);
        register.purchaseItem(1024);

        register.setMemberCard("naiithink", "121", 0.0, 100_000);

        System.out.printf("""
                Item count: %d
                Subtotal:   %.2f
                """, register.getItemCount(), register.getSubTotal());

        System.out.println();

        register.pay(3_000, 30);

        System.out.printf("""
                Subtotal:   %.2f
                Total:      %.2f
                Change:     %.2f
                """, register.getSubTotal(), register.getTotal(), register.getChange());
    }
}
