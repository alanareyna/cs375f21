Exercise9.class : Exercise9.java Canvas.class Data.class DesignElement.class FileIO.class
	javac Exercise9.java

Canvas.class : Canvas.java
	javac Canvas.java

Data.class : Data.java
	javac Data.java

DesignElement.class : DesignElement.java
	javac DesignElement.java

FileIO.class : FileIO.java
	javac FileIO.java

Ex9.jar : Exercise9.class Canvas.class Data.class DesignElement.class FileIO.class
	jar cmf Exercise9.mf Ex9.jar *.class

clean :
	rm *.class *.jar

submit : Exercise9.java Canvas.java Data.java DesignElement.java FileIO.java Exercise9.mf Ex9.jar submissionidE9.txt
	rm -rf submissionidE9
	mkdir submissionidE9
	cp Exercise9.java submissionidE9
	cp Canvas.java submissionidE9
	cp Data.java submissionidE9
	cp DesignElement.java submissionidE9
	cp FileIO.java submissionidE9
	cp Exercise9.mf submissionidE9
	cp Ex9.jar submissionidE9
	cp submissionidE9.txt submissionidE9
	tar cfvz submissionidE9.tgz submissionidE9
	cp submissionidE9.tgz ~tiawatts/cs375drop

