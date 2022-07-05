public class MainProgram {
    /*
     * UML
     * `-' private
     * `+' public
     * `#' protected
     *
     * ---
     * Class
     * ---
     * attributes
     * ---
     * methods
     *  methodName( <parameter> : Type, ...) : <return Type>
     * ---
     */

    public static void main(String[] args) {
        Student s1 = new Student("potsawat1", 20, "6410451199");
        Student s2 = new Student("potsawat2", 21, "6410451199_1");
        String a = new String("nai");

        s2.setAge(-20);

        System.out.println(s1);
        System.out.println(s2.getAge());
    }
}
