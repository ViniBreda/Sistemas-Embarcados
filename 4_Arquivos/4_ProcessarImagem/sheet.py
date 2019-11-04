from __future__ import print_function
import pickle
import os.path
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request

class GoogleSheet:
    def __init__(self, credentials: str):
        self.__credentials = credentials

    def get_sheet(self,
                spreadsheet_id: str,
                range: str,
                token_name='token.pickle',
                scopes=['https://www.googleapis.com/auth/spreadsheets.readonly']
    ):
        """Gets the values of an spread"""
        if os.path.exists(token_name):
            with open(token_name, 'rb') as token:
                creds = pickle.load(token)
        # If there are no (valid) credentials available, let the user log in.
        if not creds or not creds.valid:
            if creds and creds.expired and creds.refresh_token:
                creds.refresh(Request())
            else:
                flow = InstalledAppFlow.from_client_secrets_file(
                    'credentials.json', scopes)
                creds = flow.run_local_server(port=0)
            # Save the credentials for the next run
            with open(token_name, 'wb') as token:
                pickle.dump(creds, token)

        service = build('sheets', 'v4', credentials=creds)
        # Call the Sheets API
        sheet = service.spreadsheets()
        result = sheet.values().get(spreadsheetId=spreadsheet_id,
                                    range=range).execute()
        values = result.get('values', [])
        if not values:
            return []
        else:
            l = []
            for row in values:
                for value in row:
                    l.append(value)
            return l

if __name__ == '__main__':
    sheet = GoogleSheet('credentials.json')
    l = sheet.get_sheet('1pyHdZTw2l1tbU6EEJ7o-iuJF4YvCizwffH-VLS04GO4', 'A1:A3')
    for i in l:
        print(i)
