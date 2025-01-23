import smtplib
import ssl
from email.message import EmailMessage
from email.mime.text import MIMEText

# Email configuration
email_sender = 'networkconnect83@gmail.com'
email_password = 'Enter your App-specific password'  
email_receiver = 'archanaborase722@gmail.com'
subject = 'Text message'
body = """This is a test email implementing SMTP protocol."""

# Create the email message
em = EmailMessage()
em['From'] = email_sender
em['To'] = email_receiver
em['Subject'] = subject
em.set_content(body)

# Attach a plain text file
filename = "client-file.txt"
with open(filename, 'r') as file:
    file_content = file.read()

# Add the attachment to the email
em.add_attachment(file_content, subtype="plain", filename=filename)

# Create a secure SSL context
context = ssl.create_default_context()

# Send the email
try:
    # Use Gmail's SMTP server with TLS (port 587)
    with smtplib.SMTP('smtp.gmail.com', 587) as smtp:
        smtp.starttls(context=context)  # Start TLS encryption
        smtp.login(email_sender, email_password)  # Login to email server
        
        # Send email to the recipient
        smtp.sendmail(email_sender, email_receiver, em.as_string())
        
    print("Email sent successfully.")
    except Exception as e:
    print(f"Error: {e}")
