package th.ku.naiithink.cs211.lessons.strategy.mails;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

public class EmailClient {

    private final CipherAlgo<String, Integer> CIPHER_ALGO;

    private final EmailSystem MAILING_SYSTEM;

    public EmailClient(CipherAlgo<String, Integer> cipherAlgo, EmailSystem mailingSystem) {
        this.CIPHER_ALGO = cipherAlgo;
        this.MAILING_SYSTEM = mailingSystem;
    }

    public void send(final Email mail) {
        MAILING_SYSTEM.send(mail);
    }

    public void readAll(final String recipient) {
        List<Email> mailbox = MAILING_SYSTEM.getMailbox(recipient);

        for (Email mail : mailbox) {
            System.out.println("-----BEGIN MESSAGE-----");
            System.out.println("From: " + mail.getSender());
            System.out.println("To: " + mail.getRecipient());
            System.out.println(mail.getText());
            System.out.println("-----END MESSAGE-----");
        }
    }

    public void secureSend(final Email mail, final int key) {
        mail.setText(CIPHER_ALGO.encrypt(mail.getText(), Optional.ofNullable(key)));
        MAILING_SYSTEM.send(mail);
    }

    public void secureReadAll(final String recipient, final int key) {
        List<Email> mailbox = MAILING_SYSTEM.getMailbox(recipient);

        if (CIPHER_ALGO.requiredKeys() && key == 0)
            System.out.println("No keys supplied.");

        for (Email mail : mailbox) {
            System.out.println("-----BEGIN MESSAGE-----");
            System.out.println("From: " + mail.getSender());
            System.out.println("To: " + mail.getRecipient());
            System.out.println(CIPHER_ALGO.decrypt(mail.getText(), Optional.ofNullable(key)));
            System.out.println("-----END MESSAGE-----");
        }
    }

    public static void main(String[] args) {
        final int CAESAR_KEY = 2;

        Email email1 = new Email("Kwan", "Kate", "Hello");
        Email email2 = new Email("George", "Ken", "Hi");

        Map<String, List<Email>> mailboxes = new HashMap<>();

        mailboxes.put("Kwan", new ArrayList<>());
        mailboxes.put("George", new ArrayList<>());
        mailboxes.put("Kate", new ArrayList<>());
        mailboxes.put("Ken", new ArrayList<>());

        EmailSystem emailSystem = new EmailSystem(mailboxes);

        EmailClient kateKwanClient = new EmailClient(new CaesarCipher(), emailSystem);
        EmailClient georgeKenClient = new EmailClient(new SwitchCipher(), emailSystem);

        // Kwan says "Hello" to Kate using carsar algo
        kateKwanClient.secureSend(email1, CAESAR_KEY);

        // George says "Hi" to Ken using switch cipher
        georgeKenClient.secureSend(email2, 0);

        // Read all mails without decryption
        System.out.println(">>>>> Read all no encryption");
        kateKwanClient.readAll("Kate");
        georgeKenClient.readAll("Ken");
        System.out.println("<<<<< Read all no encryption\n");

        // Securely read all mails
        System.out.println(">>>>> Secure read all");
        kateKwanClient.secureReadAll("Kate", CAESAR_KEY);
        georgeKenClient.secureReadAll("Ken", 0);
        System.out.println("<<<<< Secure read all\n");
    }
}
