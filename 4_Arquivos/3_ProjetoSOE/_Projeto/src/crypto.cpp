/*
Arquivo onde estão as funções de criptografia do código.
*/

#include "crypto++/cryptlib.h"
#include "crypto++/sha.h"
#include "crypto++/hex.h"
#include <iostream>
using namespace std;

string SHA256(string data)
{
    byte const* pbData = (byte*) data.data();
    unsigned int nDataLen = data.size();
    byte abDigest[CryptoPP::SHA256::DIGESTSIZE];

    CryptoPP::SHA256().CalculateDigest(abDigest, pbData, nDataLen);
    string output;
    CryptoPP::HexEncoder encoder;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( abDigest, sizeof(abDigest) );
    encoder.MessageEnd();
    
    return output;
}