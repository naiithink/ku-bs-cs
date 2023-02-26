import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Node {
    private Node L;
    private Node R;
    private Node parent;
    private Character value;
    private Integer priority;
    private String code;

    public Node() {
        this.L = null;
        this.R = null;
        this.parent = null;
        this.value = null;
        this.priority = null;
        this.code = "";
    }

    public Character getValue() {
        if (this.value != null) {
            return this.value;
        }

        return null;
    }

    public Node getL() {
        return L;
    }

    public void setL(Node l) {
        L = l;
    }

    public Node getR() {
        return R;
    }

    public void setR(Node r) {
        R = r;
    }

    public Node getParent() {
        return parent;
    }

    public void setParent(Node parent) {
        this.parent = parent;
    }

    public void setValue(Character value) {
        this.value = value;
    }

    public void setPriority(Integer priority) {
        this.priority = priority;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public Integer getPriority() {
        if (this.priority != null) {
            return this.priority;
        }
        return this.L.getPriority() + this.R.getPriority();
    }

    public boolean isLeaf() {
        return (this.L == null) && (this.R == null);
    }

    public Object getName() {
        if (this.isLeaf()) {
            return this.value;
        } else {
            StringBuilder nameBuilder = new StringBuilder();
            if (this.L != null) {
                nameBuilder.append(this.L.getName());
            }
            if (this.R != null) {
                nameBuilder.append(this.R.getName());
            }
            return nameBuilder.toString();
        }
    }

    public String getCode() {
        if (this.parent == null) {
            return "";
        }
        return this.parent.getCode() + this.code;
    }

    @Override
    public String toString() {
        return "Node [value=" + value + "]";
    }
}

class Frequency {
    private List<Character> values = new ArrayList<>();
    private Map<Character, Integer> frequency = new HashMap<>();

    Frequency(String text) {
        for (int i = 0; i < text.length(); i++) {
            Character c = Character.toUpperCase(text.charAt(i));

            if (!frequency.containsKey(c))
                values.add(c);

            addFrequency(c);
        }
    }

    public void addFrequency(char c) {
        if (frequency.containsKey(c))
            frequency.put(c, frequency.get(c) + 1);
        else
            frequency.put(c, 1);
    }

    public Integer getFrequency(char c) {
        return frequency.get(c);
    }

    public List<Character> getEntry() {
        return this.values;
    }
}

class HuffmanEncoder {
    public static Node huffmanEncode(Frequency frequency) {
        List<Node> queue = new ArrayList<>();

        for (Character key : frequency.getEntry()) {
            Node node = new Node();

            node.setValue(key);
            node.setPriority(frequency.getFrequency(key));

            queue.add(node);
        }

        while (queue.size() > 1) {
            queue.sort(new Comparator<Node>() {
                @Override
                public int compare(Node a, Node b) {
                    return a.getPriority() - b.getPriority();
                }
            });

            Node left = queue.remove(0);
            Node right = queue.remove(0);
            Node newNode = new Node();

            left.setParent(newNode);
            right.setParent(newNode);

            left.setCode("0");
            right.setCode("1");

            newNode.setL(left);
            newNode.setR(right);
            newNode.setValue('\0');

            queue.add(0, newNode);
        }

        return queue.get(0);
    }

    public static void printCharCode(Node node, char c)
    {
        if (node == null)
            return;
    
        printCharCode(node.getL(), c);
        printCharCode(node.getR(), c);
    
        if (node.getValue() == c)
            System.out.print(node.getCode());
    }
}

public class Relief {
    public static void main(String[] args) {
        String text;

        try (Scanner scanner = new Scanner(System.in)) {
            text = scanner.nextLine();
        }

        Frequency frequency = new Frequency(text);

        Node node = HuffmanEncoder.huffmanEncode(frequency);

        for (char c : text.toUpperCase().toCharArray())
            HuffmanEncoder.printCharCode(node, c);
        System.out.println();
    }
}
