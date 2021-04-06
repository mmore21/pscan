# pscan

![GitHub](https://img.shields.io/github/license/mmore21/pscan)

Unix TCP port scanner written in C.

## Usage

To run pscan, clone or download this repository to a desired location and run the Makefile.

By default, pscan performs a port scan on the host machine:

<pre>
git clone https://github.com/mmore21/pscan.git
cd pscan/
make
./scanner
make clean
</pre>

You may also provide a parameter to perform a port scan on an IP address:

<pre>
./scanner 192.168.1.1
</pre>

## License

pscan is available under the [MIT License](https://github.com/mmore21/pscan/blob/master/LICENSE).

