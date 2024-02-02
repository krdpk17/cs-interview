import asyncio

async def print_message(message, delay):
    print(f"Start: {message}")
    await asyncio.sleep(delay)
    print(f"End: {message}")

async def main():
    # Create a list of coroutines with different messages and delays
    tasks = [
        print_message("Task 1", 2),
        print_message("Task 2", 1),
        print_message("Task 3", 3),
    ]

    # Run the coroutines concurrently within the event loop
    await asyncio.gather(*tasks)

# Run the event loop
if __name__ == "__main__":
    asyncio.run(main())
