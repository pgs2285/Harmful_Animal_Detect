import streamlit as st
import cv2
import os

from streamlit.elements.selectbox import SelectboxMixin

#Count Logs
path="~/Desktop/yolov5/"
file_list = [i.split(".")[0] for i in os.listdir("./yolov5/eventLog")]

sideSelectbox = st.sidebar.selectbox(
    "Plz Select a day",
    ["실시간 상황 관찰"]+file_list
)

if sideSelectbox == "실시간 상황 관찰":
    st.title('실시간 상황 관찰')

    cam_button = st.radio('', ["종료","실행"])
    live_cam = st.image([])
    cap = cv2.VideoCapture("rtsp://")

    if cam_button == "종료":
        ret, frame = cap.read()
        if ret:
            live_cam.image(frame, channels="BGR")
    elif cam_button == "실행":
        while True:
            ret, frame = cap.read()
            if ret:
                live_cam.image(frame, channels="BGR")
            cv2.waitKey(30)

            if cam_button == "종료":
                break
    cap.release()

    #미리 한프레임을 잡아놓고 버튼을 클릭했을때 실행이 되게

if sideSelectbox in file_list:
    st.title(sideSelectbox)
    with open('./yolov5/eventLog/'+sideSelectbox+'.txt','r') as file:
        contents = [x.rstrip() for x in file.readlines()[::30]]
    for i in contents:
        if i.startswith('boar'):
            boar = cv2.imread("./yolov5/boarLog/"+i)
            st.text(i.split('.')[0])
            st.image(boar, channels="BGR", caption=i.split('.')[0])
        elif i.startswith('gorani'):
            gorani = cv2.imread("./yolov5/goraniLog/"+i)
            st.text(i.split('.')[0])
            st.image(gorani, channels="BGR", caption=i.split('.')[0])
