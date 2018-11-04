#by John Connolly
#First python code
#hopefully face recognition

import cv2

#user supplied values
imagePath = sys.argv[1]
cascPath = sys.argv[2]

#haar cascade
faceCascade = cv2.CascadeClassifier(cascPath)
#read image
image = cv2.imread(imagePath)
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

#detect faces
faces = faceCascade.detectMultiScale(
    gray,
    scaleFactor=1.1,
    minNeighbors=5,
    minSize=(30,30)
    flags = cv2.cv.CV_HAAR_SCALE_IMAGE
)

print "found {0} faces!".format(len(faces))

for (x, y, w, h) in faces:
    cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255,0), 2)

cv2.imshow("faces found" ,image)
cv2.waitKey(0)