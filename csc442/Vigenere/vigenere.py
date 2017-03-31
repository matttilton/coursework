"""
Vigenere cypher encode and decoder
"""
import sys
import argparse
from random import SystemRandom

def main():
    """
    Program starting point
    """
    parser = argparse.ArgumentParser(prog='Vigenere', description='Encrypts and decrypts '
                                     + 'input using a vigenere cypher')
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('-d', help='Decrypts a string using the provided key.')
    group.add_argument('-e', help='Encrypts a string using the provided key.')
    args = parser.parse_args()
    one_time_pad_generator(182)


def encrypt(key, plaintext):
    """
    Encrypts plaintext using a key. Returns cyphertext.
    """
    print('Encrypting')

def decrypt(key, cyphertext):
    """
    Decrypts cyphertext using a key. Returns plaintext.
    """
    print('Decrypting')

def one_time_pad_generator(length):
    otpgen = SystemRandom()
    print(otpgen.randrange(10) for i in range(length))

main()
