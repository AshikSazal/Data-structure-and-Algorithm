CREATE TABLE review(id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,product_id INT,rating DOUBLE)
CREATE TABLE review2(id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,rating DOUBLE)
CREATE TABLE review3(id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,product_id INT, mean_rating DOUBLE)

DELIMITER |
CREATE event event1 ON SCHEDULE EVERY 20 SECOND DO
BEGIN
INSERT INTO review3(product_id,mean_rating)SELECT review.product_id,SUM(review.rating)/COUNT(review.product_id) 
FROM review,review2 WHERE review.product_id=review2.id GROUP BY review.product_id;

UPDATE review2,review3 SET review2.rating=review3.mean_rating WHERE review2.id=review3.product_id;

TRUNCATE review3;
END |
DELIMITER;
