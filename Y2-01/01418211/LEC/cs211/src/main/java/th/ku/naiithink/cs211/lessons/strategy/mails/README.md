## Output
    >>>>> Read all no encryption
    -----BEGIN MESSAGE-----
    From: Kwan
    To: Kate
    Jgnnq
    -----END MESSAGE-----
    -----BEGIN MESSAGE-----
    From: George
    To: Ken
    iH
    -----END MESSAGE-----
    <<<<< Read all no encryption

    >>>>> Secure read all
    -----BEGIN MESSAGE-----
    From: Kwan
    To: Kate
    Hello
    -----END MESSAGE-----
    -----BEGIN MESSAGE-----
    From: George
    To: Ken
    Hi
    -----END MESSAGE-----
    <<<<< Secure read all

## UML

```mermaid
classDiagram

class Email {
    -sender : String
    -recipient : String
    -text : String
    +getSender() String
    +setSender(sender : String)
    +getRecipient() String
    +setRecipient(recipient : String)
    +getText() String
    +setText(text : String)
}

class EmailSystem {
    -mailboxes : Map~String, List"<"Email">"~
    +send(mail : Email)
    +getMailbox(recipient : String) List~Email~
}

class CipherAlgo~T, U~ {
    <<interface>>
    requiredKeys() boolean
    encrypt(data : T, key : Optional~U~) T
    decrypt(data : T, key : Optional~U~) T
}

class CaesarCipher {
    -REQUIRED_KEYS : boolean = true
    +requiredKeys() boolean
    +encrypt(data : String, key : Optional~Integer~) String
    +decrypt(data : String, key : Optional~Integer~) String
}

class SwitchCipher {
    -REQUIRED_KEYS : boolean = false
    +requiredKeys() boolean
    +encrypt(data : String, key : Optional~Integer~) String
    +decrypt(data : String, key : Optional~Integer~) String
}

class EmailClient {
    -CIPHER_ALGO : CipherAlgo~String, Integer~
    -MAILING_SYSTEM : EmailSystem
    +send(mail, Email)
    +readAll(recipient : String)
    +secureSend(mail : Email, key : int)
    +secureReadAll(recipient : String, key : int)
    +main(args : String[])
}

EmailSystem "1" *-- "1..*" Email: Composition -- has zero (abandoned) or more
EmailClient "1" o-- "1" EmailSystem: Aggregation -- has an
CipherAlgo <|-- CaesarCipher: Inheritance -- is a
CipherAlgo <|-- SwitchCipher: Inheritance -- is a
EmailClient "1" *--> "0..1" CipherAlgo: Composition -- has zero (sending/receiving in plain text) or one (encrypted)
```
