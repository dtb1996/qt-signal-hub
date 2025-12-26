import asyncio
import websockets
import json

async def handler(websocket):
    print(f"Client connected: {websocket.remote_address}")
    try:
        while True:
            message = {
                "channel": "general",
                "payload": "Hello from server"
            }
            await websocket.send(json.dumps(message))
            print(f"Sent message to {websocket.remote_address}: {message}")  # <- debug output
            await asyncio.sleep(1)
    except websockets.exceptions.ConnectionClosedOK:
        print(f"Client {websocket.remote_address} disconnected normally")
    except websockets.exceptions.ConnectionClosedError as e:
        print(f"Client disconnected with error: {e}")

async def main():
    server = await websockets.serve(handler, "localhost", 12345)
    print("WebSocket server running on ws://localhost:12345")
    await server.wait_closed()

if __name__ == "__main__":
    asyncio.run(main())
