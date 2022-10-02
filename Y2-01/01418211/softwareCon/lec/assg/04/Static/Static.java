public class Static {
    public static int NUM = 0;
    private int n;

    public Static(int n) {
        this.n = n;
    }

    public void setN(int n) {
        this.n = n;
    }

    public int getN() {
        return n;
    }

    public void addCNUM() {
        NUM++;
    }

    public int getCNUM() {
        return NUM;
    }

    public static void main(String[] args) {
        Static foo = new Static(10);
        foo.addCNUM();
        System.out.println(foo.getN());

        Static bar = new Static(11);
        System.out.println("::" + bar.getCNUM());
        bar.addCNUM();
        System.out.println("::" + foo.getCNUM());
        System.out.println("::" + bar.getCNUM());
    }
}
