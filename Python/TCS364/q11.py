def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, n//2):
        if n % i == 0:
            return False
    return True

def create_prime_list(limit):
    prime_list = []
    for num in range(2, limit + 1):
        prime_status = "Prime" if is_prime(num) else "Non Prime"
        prime_list.append((num, prime_status))
    return prime_list

limit =int(input("Enter limit : "))
result = create_prime_list(limit)
print(result)