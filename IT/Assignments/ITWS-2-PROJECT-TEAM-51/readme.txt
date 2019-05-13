FOR HTTPS
###################################
1.sudo pip install pyopenssl
2. openssl req -x509 -newkey rsa:4096 -nodes -out cert.pem -keyout
key.pem -days 365

3. app.run(ssl_context=('cert.pem', 'key.pem'))
4. view certificates/authorities/import/ -- select cert.pem
5. if still get connection error, go to advanced, exception, drop
exception on certificate validation
6. make sure https://... is used in urls not http://...
