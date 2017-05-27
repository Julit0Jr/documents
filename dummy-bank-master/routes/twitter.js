const bcrypt = require('bcrypt');
const express = require('express');
const User = require('../models').User;
const Account = require('../models').Account;
const router = new express.Router();
const passport = require('../config/passport');
router.get('/auth/twitter', passport.authenticate('twitter'));
router.get('/auth/twitter/callback',
    passport.authenticate('twitter', {
        failureRedirect: '/'
    }),
    function(req, res) {
        req.session.currentUser = req.user.email;
        res.redirect('/profile');
    }
);

module.exports = router;