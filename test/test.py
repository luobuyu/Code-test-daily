from base64 import encode
import subprocess
import queue
import threading

def main1(name, path, jobs, logs):
    while True:
        if not jobs.empty():
            jobid = jobs.get()
            order = path + ' ' + name + ' ' + jobid + ' < ' + ' ./log.txt'
            print(name, '开始执行任务', jobid)
            ret = subprocess.run(order, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, encoding='gbk')
            print(name, '结束执行任务', jobid)
            logs.put(ret.stderr)
        else:
            break
    print(name, '结束')


if __name__ == "__main__":
    path='.\\build\\main.exe'
    jobs = queue.Queue()
    logs = queue.Queue()
    for i in range(10):
        time = 6000
        jobs.put(str(i + 1) + ' ' + str(time))
    
    pool = 10
    threads = []

    for i in range(pool):
        thread = threading.Thread(target=main1, args=('线程' + str(i + 1), path, jobs, logs))
        thread.start()
        threads.append(thread)
    for thread in threads:
        thread.join()
    with open('./log.txt', 'a') as file:
        while logs.qsize():
            file.writelines(logs.get())