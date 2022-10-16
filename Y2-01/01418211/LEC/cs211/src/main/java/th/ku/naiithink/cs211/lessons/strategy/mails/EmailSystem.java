package th.ku.naiithink.cs211.lessons.strategy.mails;

import java.util.List;
import java.util.Map;

public class EmailSystem {

    private Map<String, List<Email>> mailboxes;

    public EmailSystem(Map<String, List<Email>> mailboxes) {
        this.mailboxes = mailboxes;
    }

    public void send(Email mail) {
        List<Email> box = mailboxes.get(mail.getRecipient());
        box.add(mail);
    }


    public List<Email> getMailbox(final String recipient) {
        if (mailboxes.containsKey(recipient) == false) {
            System.err.println("Recipient not found.");
            return null;
        }

        return mailboxes.get(recipient);
    }
}
