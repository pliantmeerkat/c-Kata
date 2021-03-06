/*
 * encryptionTest.cpp
 *
 *  Created on: 23 Aug 2018
 *      Author: jackbranch
 */

#include "gtest/gtest.h"
#include "encryption.h"

namespace EncryptionTesting
{
	class EncryptionTest: public ::testing::Test
	{
	protected:
		Encryption * encrypt;
		std::string inputString;

		virtual void SetUp()
		{
			inputString = "Hello WOrldwfhe da rihirevujsdnfuweuh";
		}
	};

	TEST_F(EncryptionTest, isNumberPrime)
	{
		ASSERT_TRUE(encrypt->isNumberPrime(7));
		ASSERT_FALSE(encrypt->isNumberPrime(10));
	}

	TEST_F(EncryptionTest, isRelativePrime)
	{
		ASSERT_TRUE(encrypt->isRelativePrime(12, 13));
		ASSERT_FALSE(encrypt->isRelativePrime(12, 20));
	}

	TEST_F(EncryptionTest, generatePrimeInt)
	{
		int randInt = encrypt->generatePrimeInt();
		ASSERT_TRUE(encrypt->isNumberPrime(randInt));
	}

	TEST_F(EncryptionTest, generateEncryptionKeys)
	{
		encrypt->generateEncryptionKeys();
		ASSERT_FALSE(encrypt->isNumberPrime(encrypt->rKey));
	}

	TEST_F(EncryptionTest, encryptData)
	{
		ASSERT_NE(encrypt->encryptData(inputString), inputString);
	}

	TEST_F(EncryptionTest, decryptData)
	{
		std::string encryptString = encrypt->encryptData(inputString);
		int qKey = encrypt->qKey;
		ASSERT_EQ(encrypt->decryptData(encryptString, qKey), inputString);
	}

}

