#!/usr/bin/python3
"""Determines the winner of a prime number game between Maria and Ben."""

def isWinner(x, nums):
    """
    Determines who won the most rounds."""
    
    def is_prime(n):
        """Checks if a number is prime."""
        if n < 2:
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True

    def prime_count(n):
        """Counts primes up to n."""
        primes = [True] * (n + 1)
        count = 0
        for i in range(2, n + 1):
            if primes[i]:
                count += 1
                for j in range(i * i, n + 1, i):
                    primes[j] = False
        return count

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        prime_moves = prime_count(n)
        if prime_moves % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None