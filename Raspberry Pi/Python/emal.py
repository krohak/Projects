import smtplib
GMAIL_USER = 'your_email'
GMAIL_PASS = 'your_pass'
SMTP_SERVER = 'smtp.gmail.com'
SMTP_PORT = 587

def send_email(recipient, subject, text):
	smtpserver = smtplib.SMTP(SMTP_SERVER, SMTP_PORT)
	smtpserver.ehlo()
	smtpserver.starttls()
	smtpserver.ehlo
	smtpserver.login(GMAIL_USER, GMAIL_PASS)
	header = 'To:' + recipient + '\n' + 'From: ' + GMAIL_USER
	header = header + '\n' + 'Subject:' + subject + '\n'
	msg = header + '\n' + text + ' \n\n'
	smtpserver.sendmail(GMAIL_USER, recipient, msg)
	smtpserver.close()

send_email('rohaksinghal14@gmail.com', 'sub', 'this is text')
