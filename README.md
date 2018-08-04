## zny_yespower_python
_python module for pow verification_

### introduction
yespower is a proof-of-work (PoW) focused fork of yescrypt, which in turn builds upon scrypt. While yescrypt is a password-based key derivation function (KDF) and password hashing scheme, and thus is meant for processing passwords, yespower is meant for processing trial inputs such as block headers (including nonces) in PoW-based blockchains.

### yespower versions

yespower includes optimized and specialized re-implementation of the obsolete yescrypt 0.5 (based off its first submission to Password Hashing Competition back in 2014) now re-released as yespower 0.5, and brand new proof-of-work specific variation known as yespower 1.0.

yespower 0.5 is intended as a compatible upgrade for cryptocurrencies that already use yescrypt 0.5 (providing a few percent speedup), and yespower 1.0 may be used as a further upgrade or a new choice of PoW by those and other cryptocurrencies and other projects.

There are many significant differences between yespower 0.5 and 1.0 under the hood, but the main user visible difference is yespower 1.0 greatly improving on GPU-unfriendliness in light of improvements seen in modern GPUs (up to and including NVIDIA Volta) and GPU implementations of yescrypt 0.5. This is achieved mostly through greater use of CPUs' L2 cache.

The version of algorithm to use is requested through parameters, allowing for both algorithms to co-exist in client and miner implementations (such as in preparation for a cryptocurrency hard-fork and/or supporting multiple cryptocurrencies in one program).

### installation:
```bash
python setup.py install
sudo python setup.py install --record files.txt && sudo chown $USER:$USER files.txt
```

### rebuild & reinstall:
```bash
rm -rf build/ & \
python setup.py build && \
sudo python setup.py install --record files.txt && sudo chown $USER:$USER files.txt
```

### uninstall
```bash
cat files.txt | sudo xargs rm -rf
```

### testing:
python block.py

_note: libssl1.0 required (libssl1.1 wont work)_
