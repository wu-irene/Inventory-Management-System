#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// using CHAT GPT template to test sending email API

const string COMMAND_BASE = "curl -X POST -H \"Authorization: Bearer ";
const string API_ENDPOINT = "https://gmail.googleapis.com/gmail/v1/users/me/messages/send";

// Function to send the email using the Gmail API
void sendEmail(const string& accessToken, const string& rawEmailContentBase64) {
    string command = COMMAND_BASE + accessToken +
                     "\" -H \"Content-Type: application/json\" -d '"
                     "{ \"raw\": \"" + rawEmailContentBase64 + "\" }' " + API_ENDPOINT;

    int result = system(command.c_str());

    if (result == 0) {
        cout << "Email sent successfully." << endl;
    } else {
        cerr << "Failed to send email." << endl;
    }
}

int main() {
    const string ACCESS_TOKEN = "YOUR_ACCESS_TOKEN"; // Replace with access token from google playground
    string email_content = R"(
To: recipient@example.com
Subject: Test Email

This is a test email sent via Gmail API.
)"
    string base64_encoded_content = base64_encode(reinterpret_cast<const unsigned char*>(email_content.c_str()), email_content.length()); 

    sendEmail(ACCESS_TOKEN, base64_encoded_content);

    return 0;
}

#endif
