# แบบฝึกหัดเรื่อง Design Pattern (Strategy Pattern)

วิชา 01418211 การสร้างซอฟต์แวร์

พิจารณาโปรแกรมด้านล่างที่ใช้ส่งอีเมลและเข้ารหัสข้อความในอีเมล โดยสามารถเลือกใช้วิธีเข้ารหัสได้ 2 แบบ คือ แบบซีซ่าร์และแบบสลับ
ตัวอักษร ด้วยเมธอด `sendCaesar` และ `sendSwitchCipher` ตามลําดับ

```java
public class Email {
    private String sender;
    private String recipient;
    private String text;

    // ... โค้ด constructor, getter, setter ต่าง ๆ ...
}

public class EmailSystem {
    private HashMap<String, List<Email>> mailboxes;

    public void sendCaesar(Email m, int key) {
        // encrypt
        char[] data = m.getText().toCharArray();
        for (int i = 0; i < data.length; i++) {
            data[i] = (char) (data[i] + key);
        }
        m.setText(new String(data));
        // deliver to corresponding mailbox
        List<Email> box = mailboxes.get(m.getRecipient());
        box.add(m);
    }

    public void sendSwitchCipher(Email m) {
        // encrypt
        char[] data = m.getText().toCharArray();
        for (int i = 0; i < data.length - 1; i += 2) {
            char tmp = data[i];
            data[i] = data[i + 1];
            data[i + 1] = tmp;
        }
        m.setText(new String(data));
        // deliver to corresponding mailbox
        List<Email> box = mailboxes.get(m.getRecipient());
        box.add(m);
    }
    // . . . constructor และโค้ดอื่น ๆ
}
```

โค้ดด้านล่างแสดงตัวอย่างการส่งและเข้ารหัสข้อความในอีเมล

```java
public static void main(String[] args) {
    Email email1 = new Email("Kwan", "Kate", "Hello");
    Email email2 = new Email("George", "Ken", "Hi");
    EmailSystem emailSystem = new EmailSystem();
    emailSystem.sendCaesar(email1, 2);
    emailSystem.sendSwitchCipher(email2);
}
```

เนื่องจากการเข้ารหัสมีหลายวิธีเราจึงต้องการโปรแกรมที่มีความยืดหยุ่น สามารถสลับสับเปลี่ยนวิธีการเข้ารหัส รวมถึงเพิ่มวิธีใหม่ เข้าไปได้
โดยไม่ต้องแก้ไขโค้ดของคลาส `EmailSystem` จงปรับแก้โค้ดโดยให้นํา strategy pattern มาช่วย

## โดยปรับดังนี้

1. สร้าง interface และคลาส strategy ต่างๆ
1. ปรับแก้เมธอด `send` ให้รองรับโค้ดแบบ stragety pattern
1. แสดงตัวอย่างการเรียกใช้เมธอด `send` แบบใหม่ในเมธอด `main()` ด้วย
1. วาดแผนภาพ UML เพื่อแสดงถึงโครงสร้างคลาสของโปรแกรมนี้
