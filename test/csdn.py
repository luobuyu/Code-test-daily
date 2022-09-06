import queue
import threading
import time

exitFlag = 0

class myThread(threading.Thread):
   def __init__(self, threadID, name, q, t):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.name = name
      self.q = q
      self.t = t

   def run(self):
      print("Starting " + self.name)
      process_data(self.name, self.q, self.t)
      print("Exiting " + self.name)

def process_data(threadName, q, t):
   while True:
      if not workQueue.empty():
         data = q.get()
         print("%s processing %s" % (threadName, data))
      else:
        break
      time.sleep(t)


threadList = ["Thread-1", "Thread-2", "Thread-3"]
nameList = ["One", "Two", "Three", "Four", "Five"]
queueLock = threading.Lock()
workQueue = queue.Queue()
threads = []
threadID = 1


# 填充队列
queueLock.acquire()
for word in range(20):
   workQueue.put(word)
queueLock.release()
# 创建新线程
for tName in range(5):
    t = 1
    if tName == 4:
        t = 20
    thread = myThread(threadID, tName, workQueue, t)
    thread.start()
    threads.append(thread)
    threadID += 1


# 等待所有线程完成
for t in threads:
   t.join()
print("Exiting Main Thread")